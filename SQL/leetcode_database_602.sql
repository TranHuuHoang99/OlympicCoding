# Write your MySQL query statement below
WITH cnt_accepter AS (
    SELECT
        requester_id,
        COUNT(accepter_id) AS numb
    FROM
        RequestAccepted
    GROUP BY
        requester_id
),
cnt_requester AS (
    SELECT
        accepter_id,
        COUNT(requester_id) AS numb
    FROM
        RequestAccepted
    GROUP BY
        accepter_id
),
id_table AS (
    SELECT
        requester_id as id
    FROM RequestAccepted
    UNION
    SELECT
        accepter_id
    FROM
        RequestAccepted
),
sum_table AS (
    SELECT
        i.id,
        COALESCE(cr.numb, 0) + COALESCE(ca.numb, 0) AS numb
    FROM
        id_table i
    LEFT JOIN
        cnt_requester cr
    ON
        cr.accepter_id = i.id
    LEFT JOIN
        cnt_accepter ca
    ON
        ca.requester_id = i.id
),
max_val AS (
    SELECT
        MAX(numb) AS numb
    FROM
        sum_table
)
SELECT
    s.id,
    s.numb AS num
FROM
    sum_table s
INNER JOIN
    max_val m
ON
    s.numb = m.numb
