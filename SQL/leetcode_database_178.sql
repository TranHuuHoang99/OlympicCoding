# Write your MySQL query statement below
WITH sortedTable AS (
    SELECT
        DENSE_RANK() OVER (ORDER BY score DESC) as sorted_order,
        score
    FROM
        Scores
)
SELECT
    score,
    sorted_order AS `rank`
FROM
    sortedTable