SELECT Candidate.name
FROM Candidate
INNER JOIN Vote
  ON (Candidate.id = Vote.candidateId)
GROUP BY Candidate.id
ORDER BY COUNT(Vote.id) DESC
LIMIT 1;
