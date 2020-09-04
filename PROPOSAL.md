# Proposal: Space Invaders

## Synopsis
The Game will six elements: 	
- A set of space invaders positioned in a rectangle that move in unison and fire laser guns randomly,
each consequent layer of invaders are worth increasing amounts of points. The aliens regenerate when an entire
set is cleared. The sets get progressively faster. 
- Three defense barriers that degrade with hits from lasers
- The user-controlled laser cannon 
- A space ship that floats at the top of the screen at random times, worth a random amount of points
- The score of the user in the top left corner
- The user starts with three lives, with one being added each time a set is cleared. This will be displayed in the
lower right corner.

## Functional requirements
1. The aliens are placed in a rectangular grid near the top of the screen 
2. The aliens move slowly in unison 
3. When all the aliens are cleared, the entire set is regenerated. 
4. The next set of aliens move faster than the previous. 
5. The # of lives of the user will be increased by 1 each set that is cleared. 
6. Occasionally a ship will cross the screen and be worth an unknown amount of points.
7. The score is dynamically counted
8. A random* front-line alien will fire at the user
9. The laser canon is controlled by the left and right arrow keys, and it is fired with a single press of the space bar.
The canon cannot be fired continuously. 
10. The defense barriers degrade** and eventually disappears with enough hits from the aliens or user
11. Lasers kill exactly one alien, and can only move in the y direction 
12. Once the user has lost all lives, a Game Over screen appears over the current game state

## Open questions
* How would you pick the alien to fire?
** How would you show degradation of the barriers?