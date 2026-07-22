# SOLUTION 1
# solution using LEAD AND DISTINCT
WITH temp AS (
    SELECT
        num,
        LEAD(num, 1) OVER (ORDER BY id) AS next_num,
        LEAD(num, 2) OVER (ORDER BY id) AS next_next_num
    FROM
        Logs
)
SELECT
    DISTINCT num AS ConsecutiveNums
FROM
    temp
WHERE
    num = next_num AND num = next_next_num

# SOLUTION 2
# solution use ROW_NUMBER
WITH temp_table AS (
    SELECT
        num,
        (ROW_NUMBER() OVER (ORDER BY id) - ROW_NUMBER() OVER (PARTITION BY num ORDER BY id)) as diff_order
    FROM
        Logs
)
SELECT
    DISTINCT num AS ConsecutiveNums
FROM
    temp_table
GROUP BY
    num, diff_order
HAVING
    COUNT(num) >= 3
