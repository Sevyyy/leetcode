select t1.FirstName, t1.LastName, t2.City, t2.State
from Person as t1 left outer join Address as t2 on(t1.PersonID = t2.PersonID)