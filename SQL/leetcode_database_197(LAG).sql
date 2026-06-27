# Write your MySQL query statement below
SELECT
    id AS Id
FROM (
    SELECT
        id,
        LAG(temperature, 1) OVER (ORDER BY recordDate ASC) AS previous_temp,
        LAG(recordDate, 1) OVER (ORDER BY recordDate ASC) AS previous_date,
        temperature,
        recordDate
    FROM
        Weather
) AS selected
WHERE
    temperature > previous_temp AND
    DATEDIFF(recordDate, previous_date) = 1
