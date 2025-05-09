WITH RECURSIVE hours AS (
    SELECT 0 as hr
    UNION ALL
    SELECT hr + 1
    FROM hours
    WHERE hr < 23
)
SELECT hours.hr AS HOUR, COALESCE(o.cnt, 0) 
FROM hours LEFT JOIN (
    SELECT
        HOUR(DATETIME) AS hr,
        COUNT(*) AS cnt
    FROM ANIMAL_OUTS
    GROUP BY hr
) AS o
ON o.hr = hours.hr
ORDER BY hours.hr;