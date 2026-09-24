# Write your MySQL query statement below
-- SELECT
--     id,
--     CASE
--         WHEN id IN (SELECT DISTINCT id FROM Tree WHERE p_id IS NULL) THEN 'Root'
--         WHEN id IN (SELECT DISTINCT p_id FROM Tree WHERE  p_id IS NOT NULL) THEN 'Inner'
--         ELSE 'Leaf'
--     END AS type
-- FROM
--     Tree


WITH Root_table AS (
    SELECT
        id
    FROM
        Tree
    WHERE
        p_id IS NULL
), Inner_table AS (
    SELECT DISTINCT
        p_id AS id
    FROM
        Tree
    WHERE
        p_id IS NOT NULL
        AND p_id NOT IN (SELECT id FROM Root_table)
), Leaf_table AS (
    SELECT
        id
    FROM
        Tree
    WHERE
        id NOT IN (SELECT id FROM Root_table)
        AND id NOT IN (SELECT id FROM Inner_table)
)
SELECT
    id,
    'Root' AS type
FROM
    Root_table
UNION ALL
SELECT
    id,
    'Inner' AS type
FROM
    Inner_table
UNION ALL
SELECT
    id,
    'Leaf' AS type
FROM
    Leaf_table
