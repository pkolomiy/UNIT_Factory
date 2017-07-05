select count(date) as 'movies' from member_history where date(date) between '2006-10-30' and '2007-07-27' or date(date) like '%12-24';
