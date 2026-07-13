# Write your MySQL query statement below
WITH sortedSalary AS (
    SELECT
        salary,
        DENSE_RANK() OVER (ORDER BY salary DESC) as numbOrder
    FROM
        Employee
),
cntDistinctSalary AS (
    SELECT
        COUNT(DISTINCT salary) AS cnt
    FROM
        sortedSalary
)
SELECT
    CASE
        WHEN (
            SELECT
                cnt
            FROM
                cntDistinctSalary
        ) < 2 THEN NULL
        ELSE (
            SELECT
                salary
            FROM
                sortedSalary
            WHERE
                numbOrder = 2
            LIMIT
                1
        )
    END AS SecondHighestSalary
