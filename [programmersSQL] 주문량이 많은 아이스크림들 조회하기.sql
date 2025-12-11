-- -- [programmersSQL] 주문량이 많은 아이스크림들 조회하기

SELECT 
    FIRST_HALF.FLAVOR
FROM 
    FIRST_HALF 
    JOIN JULY ON FIRST_HALF.FLAVOR = JULY.FLAVOR
GROUP BY 
    FIRST_HALF.FLAVOR
ORDER BY 
    (FIRST_HALF.TOTAL_ORDER + SUM(JULY.TOTAL_ORDER)) DESC
LIMIT 3;

---------------------------------

SELECT ST.FLAVOR
FROM
    (
        SELECT
            UT.FLAVOR, SUM(TOTAL_ORDER) AS TOTAL_ORDER_SUM
        FROM
            (
                SELECT FLAVOR, TOTAL_ORDER
                FROM FIRST_HALF
                
                UNION ALL
                
                SELECT FLAVOR, TOTAL_ORDER
                FROM JULY
            )AS UT
        GROUP BY FLAVOR
    )AS ST
ORDER BY ST.TOTAL_ORDER_SUM DESC
LIMIT 3;