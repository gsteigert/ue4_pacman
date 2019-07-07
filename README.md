# Pacman

A Pacman Remake developed with Unreal Engine 4 to learn how to use this engine.
Source code comments will be verbose, since the goal of this project is learning.
Some [videos](https://www.youtube.com/playlist?list=PLniLEzAERZnIWAflpOPpguI-1GcJ7tTq-) were
uploaded to YouTube to better track the game state, as it's developed.

## Running the functional tests

1. Open the project in Unreal Engine editor.
1. Head to `Window > Test Automation`
1. Make sure a device is selected in the `Session Browser` tab
1. In the `Automation` tab, select `Product Tests`
1. Select the checkbox to the left of `Project > Functional Tests`
1. Hit the `Start Tests` button

## Debugging the path finding algorithm

After pressing the `Play button`, just tap the single quote key.
Then use the numpad keys to toggle specific features, like navmesh, AI, behavior tree, etc.

## Tricks learned

* Snap to floor: select an object then press `END` to snap it to the floor.
* Snap to grid: select an object then press `CTRL + END` to snap its pivot point to the closest grid intersection.
* Change grid size: use square brackets to either increase/decrease the grid size.
* Rotate around an object: select an object, hold `ALT + Mouse 1` and move the mouse around.
* Zoom-in/out in place: hold `Mouse 1` and then hold `C` to zoom in or `Z` to zoom out.

## Logging

* `check()` will halt execution with a meaningful error message
* `ensure()` won't halt execution but will log an error and generate a debug call stack

## Delegates

[Delegates](https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Delegates/index.html) support invoking signature-based function references, therefore they're useful to implement things like listeners, callbacks, events and notifications. There are different delegate types:
 * Single cast: can only invoke one bound function but may specify a return type; make sure to check if the delegate is bound before executing it;
 * Multi cast: can invoke many functions at once, but can't use return types;
 * Event: like dynamic cast but only the class that defines it is allowed to broadcast;
 * Dynamic cast: supports single and multi cast plus serialization (adds a performance penalty), which is very useful for using it through blueprints.
