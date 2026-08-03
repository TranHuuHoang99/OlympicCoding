# Write your MySQL query statement below
WITH cnt_table AS (
    SELECT
        managerId
    FROM
        Employee
    GROUP BY
        managerId
    HAVING
        COUNT(managerId) > 4
)
SELECT
    e.name
FROM
    Employee e
INNER JOIN
    cnt_table c
ON
    e.id = c.managerId
