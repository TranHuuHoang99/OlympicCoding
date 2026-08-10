# Write your MySQL query statement below
WITH cnt_tiv_2015 AS (
    SELECT
        pid,
        COUNT(*) OVER (PARTITION BY tiv_2015) AS numb_tiv_2015
    FROM
        Insurance
),
cnt_lat_lon AS (
    SELECT
        pid
    FROM
        Insurance
    GROUP BY
        lat, lon
    HAVING
        COUNT(*) = 1
)
SELECT
    ROUND(SUM(i.tiv_2016), 2) AS tiv_2016
FROM
    Insurance i
INNER JOIN
    cnt_tiv_2015 c1,
    cnt_lat_lon c2
WHERE
    i.pid = c1.pid AND i.pid = c2.pid AND c1.numb_tiv_2015 >= 2
