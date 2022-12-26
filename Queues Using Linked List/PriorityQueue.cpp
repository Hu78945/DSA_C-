#include <iostream>
#include "Queue.h"

// fist type mostly used in opearting systems
// for examplen java jvm allow multi threadinng so it allow priority upon threads

// for examplewe take three priorityies
// elemenrs ----> A  B  C  D  E  F  G  H  I  J
// priority ----> 1  1  2  3  2  1  2  3  2  2
// Samaller the number hiher the priority or larger the number smaller the priority

// For the implememtation we have only three priorities so we wil take three queues

Queue q1 = {};
Queue q2 = {};
Queue q3 = {};

// so depending upon the priority they will be placedin the q accordingly
// whenever we ar delting we are deleing from the highest priority and if it is empty we will move to the other queue
