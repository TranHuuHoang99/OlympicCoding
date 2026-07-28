# Write your MySQL query statement below
WITH fil_emp AS (
    SELECT
        MAX(salary) AS max_sal,
        departmentId
    FROM
        Employee
    GROUP BY
        departmentId
),
max_emp AS (
    SELECT
        e.salary AS max_sal,
        e.departmentId AS max_depart,
        e.name AS max_name
    FROM
        Employee e
    INNER JOIN
        fil_emp f
    ON
        e.salary = f.max_sal
    AND
        e.departmentId = f.departmentId
)
SELECT
    d.name AS Department,
    m.max_name AS Employee,
    m.max_sal AS Salary
FROM
    max_emp m
INNER JOIN
    Department d
ON
    m.max_depart = d.id
