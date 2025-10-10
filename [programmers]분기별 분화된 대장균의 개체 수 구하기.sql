-- [programmers] 분기별 분화된 대장균의 개체 수 구하기
with quarter_bug as(
    select ID, 
        CASE
            WHEN MONTH(ed.DIFFERENTIATION_DATE) between 1 and 3 
            THEN '1Q'
            WHEN MONTH(ed.DIFFERENTIATION_DATE) between 4 and 6 
            THEN '2Q'
            WHEN MONTH(ed.DIFFERENTIATION_DATE) between 7 and 9 
            THEN '3Q'
            ELSE '4Q'
        END as qt
    from ECOLI_DATA ed
)
select 
    qt as QUARTER , count(*) as ECOLI_COUNT
from quarter_bug
group by qt
order by qt;