# Write your MySQL query statement below
WITH cont_table AS (
    SELECT
        player_id,
        event_date,
        LEAD(event_date, 1) OVER (
            PARTITION BY player_id
            ORDER BY event_date ASC
        ) AS next_event_date,
        MIN(event_date) OVER (
            PARTITION BY player_id
            ORDER BY event_date ASC
        ) AS first_login
    FROM
        Activity
),
total_player AS (
    SELECT
        COUNT(DISTINCT player_id) AS total
    FROM
        Activity
),
total_cont_player AS (
    SELECT
        COUNT(player_id) AS total_cont
    FROM
        cont_table
    WHERE
        TIMESTAMPDIFF(DAY, event_date, next_event_date) = 1 AND
        event_date = first_login
),
final_total_cont_player AS (
    SELECT
        CASE
            WHEN total_cont IS NULL THEN 0
            ELSE total_cont
        END AS final_answer
    FROM
        total_cont_player   
)
SELECT
    ROUND(f.final_answer / t.total, 2) AS fraction
FROM
    final_total_cont_player f,
    total_player t
