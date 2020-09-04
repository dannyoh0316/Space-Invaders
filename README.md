# [Space Invaders]

## Instructions

[FINAL TODO]

## Changes from proposal

[FINAL TODO]

Model tests:
1. L1141. The first model test is testing whether or not a new set of aliens
is created after the first set is destroyed. I created a new set of aliens that was empty.
Then I added one alien using alien_update. I checked the see that set was correctly not
empty. I then cleared the set, used alien_update again, and expected alien_update to refill
the set. As expected, when I checked if the set was not empty, it returned true.
2. L1154. The second test checked what happens if the user hit the mystery ship. Simply,
the test just shows that when the mystery ship is hit, 5000 points are added to the score.
3. L1165. The third test shows how the barrier degrades. Simply, I showed how every time
a laser was spawned right in the barrier hit box, and barrier_update was called, the barrier's
health would decrease by one. Eventually, when the barrier's health was one and it was
hit again, the barriers_ vector in the model was empty, which was expected as when a barrier was
destroyed, it was popped from the barriers_ vector.
4. L1188. The fourth test is for when a laser hits an alien. To show this test case, I first created
a whole set of aliens in the aliens_ vector. I checked to see that the game's score was indeed 0. I then
spawned a laser where the top left alien's position is. Calling alien_update(), we see that the score of the game
has been updated, meaning that the alien has been hit.
5. L1199. The last test was when a laser hit the user. Using the Test_access struct, I created a
user with one life. The test shows that the user is not dead, and the game is not over.
However, when hit with a laser, when user_update() is called, we see that now the user is indeed dead.
Also, the game is over.

[FINAL TODO]

## Answers to open questions

[FINAL TODO]