select A.machine_id, round(AVG(B.timestamp - A.timestamp),3) as processing_time from Activity  A join Activity  B 
where A.machine_id = B.machine_id and
 A.process_id = B.process_id and
 B.activity_type = 'end' and
 A.activity_type = 'start' group by machine_id;

