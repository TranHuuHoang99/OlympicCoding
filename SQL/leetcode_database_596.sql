# Write your MySQL query statement below
WITH count_filter AS (
    SELECT
        class,
        COUNT(class) as signup_class
    FROM
        Courses
    GROUP BY
        class
)
SELECT
    class
FROM
    count_filter
WHERE
    signup_class >= 5 