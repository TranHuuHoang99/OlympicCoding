# Write your MySQL query statement below
SELECT
    employee_id
FROM
    (SELECT * FROM Employees LEFT JOIN Salaries USING(employee_id)
    UNION
    SELECT * FROM Employees RIGHT JOIN Salaries USING(employee_id))
AS full_infor
WHERE
    name IS NULL OR salary IS NULL
ORDER BY
    employee_id ASC