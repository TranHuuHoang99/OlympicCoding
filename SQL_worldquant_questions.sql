SELECT 
    u.user_name
    COUNT(CASE WHEN LEFT(t.stock_id, 2) = '19' THEN 1 END) AS '2019',
    COUNT(CASE WHEN LEFT(t.stock_id, 2) = '20' THEN 1 END) AS '2020',
    COUNT(CASE WHEN LEFT(t.stock_id, 2) = '21' THEN 1 END) AS '2021'
FROM 
    users u
LEFT JOIN 
    transactions t ON u.user_id = t.user_id
GROUP BY 
    u.user_id, 
    u.user_name;
