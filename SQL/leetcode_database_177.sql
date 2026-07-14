CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    RETURN (
        # Write your MySQL query statement below.
        WITH sortedList AS (
            SELECT
                salary,
                DENSE_RANK() OVER (ORDER BY salary DESC) as rnk
            FROM
                Employee
        )
        SELECT
            salary
        FROM
            sortedList
        WHERE
            rnk = N
        LIMIT
            1
    );
END