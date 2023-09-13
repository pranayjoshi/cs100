#include <stdio.h>
#include <string.h>

int main() {
    char location[10];

    printf("You are at the begining of a Wumpus Hunt. Where shall we hunt?: forest, river, cave, or cliffs?\n");
    scanf("%s", location);

    if (strcmp(location, "forest") == 0) {
        char forest_location[50];
        printf("From forest: redwood, hardwood, pine?\n");
        scanf("%s", forest_location);

        if (strcmp(forest_location, "redwood") == 0) {
            char redwood_location[50];
            printf("From redwood: ground, canopy, pine?\n");
            scanf("%s", redwood_location);

            if (strcmp(redwood_location, "ground") == 0) {
                char ground_location[50];
                printf("From ground: humboldt, calaveras?\n");
                scanf("%s", ground_location);

                if (strcmp(ground_location, "humboldt") == 0) {
                    printf("THE HUNT IS OVER!\nHippies surround you in a drum circle!\n");
                } else if (strcmp(ground_location, "calaveras") == 0) {
                    printf("THE HUNT IS OVER!\nLoggers stopped you to count your rings!\n");
                } else {
                    printf("Invalid location!\n");
                }
            } else if (strcmp(redwood_location, "canopy") == 0) {
                printf("THE HUNT IS OVER!\nYou fell from the top of a very tall tree!\n");
            } else if (strcmp(redwood_location, "pine") == 0) {
                printf("THE HUNT IS OVER!\nIt is a sappy ending!\n");
            } else {
                printf("Invalid location!\n");
            }
        } else if (strcmp(forest_location, "hardwood") == 0) {
            char hardwood_location[50];
            printf("From hardwood: oak, maple?\n");
            scanf("%s", hardwood_location);

            if (strcmp(hardwood_location, "oak") == 0) {
                printf("THE HUNT IS OVER!\nYou are lost!\n");
            } else if (strcmp(hardwood_location, "maple") == 0) {
                char maple_location[50];
                printf("From maple: pancakes, waffles, frenchtoast?\n");
                scanf("%s", maple_location);

                if (strcmp(maple_location, "pancakes") == 0) {
                    char pancakes_location[50];
                    printf("From pancakes: chocolatechip, blueberry?\n");
                    scanf("%s", pancakes_location);

                    if (strcmp(pancakes_location, "chocolatechip") == 0) {
                        printf("THE HUNT IS OVER!\nYou are distracted!\n");
                    } else if (strcmp(pancakes_location, "blueberry") == 0) {
                        printf("THE HUNT IS OVER!\nYou take the bait!\n");
                    } else {
                        printf("Invalid location!\n");
                    }
                } else if (strcmp(maple_location, "waffles") == 0) {
                    char waffles_location[50];
                    printf("From waffles: regular, wholewheat?\n");
                    scanf("%s", waffles_location);

                    if (strcmp(waffles_location, "regular") == 0) {
                        printf("THE HUNT IS OVER!\nYou fell asleep!\n");
                    } else if (strcmp(waffles_location, "wholewheat") == 0) {
                        printf("THE HUNT IS OVER!\nNature calls!\n");
                    } else {
                        printf("Invalid location!\n");
                    }
                }else if (strcmp(maple_location, "frenchtoast") == 0) {
                    printf("THE HUNT IS OVER!\nBut french toast is not a bad idea!\n");
                } else {
                    printf("Invalid location!\n");
                }
            } else {
                printf("Invalid location!\n");
            }
        } else if (strcmp(forest_location, "pine") == 0) {
            char pine_location[50];
            printf("From pine: conifer, shrub?\n");
            scanf("%s", pine_location);

            if (strcmp(pine_location, "conifer") == 0) {
                printf("THE HUNT IS OVER!\nIt is a sappy ending!\n");
            } else if (strcmp(pine_location, "shrub") == 0) {
                printf("THE HUNT IS OVER!\nYou caught a snipe, but not a wumpus!\n");
            } else {
                printf("Invalid location!\n");
            }
        } else {
            printf("Invalid location!\n");
        }
    } else if (strcmp(location, "river") == 0) {
        char river_location[50];
        printf("From river: upstream, downstream?\n");
        scanf("%s", river_location);

        if (strcmp(river_location, "upstream") == 0) {
            printf("THE HUNT IS OVER!\nYou lost your paddle!\n");
        } else if (strcmp(river_location, "downstream") == 0) {
            char downstream_location[50];
            printf("From downstream: rapids, calm?\n");
            scanf("%s", downstream_location);

            if (strcmp(downstream_location, "rapids") == 0) {
                printf("THE HUNT IS OVER!\nYou capsized and lost all your equipment!\n");
            } else if (strcmp(downstream_location, "calm") == 0) {
                printf("THE HUNT IS OVER!\nYou are dead in the water. Mosquitoes feast on your unlucky route!\n");
            } else {
                printf("Invalid location!\n");
            }
        } else {
            printf("Invalid location!\n");
        }
    } else if (strcmp(location, "cave") == 0) {
        char cave_location[50];
        printf("From cave: tunnel, cavern?\n");
        scanf("%s", cave_location);

        if (strcmp(cave_location, "tunnel") == 0) {
            printf("THE HUNT IS OVER!\nYou found a bear. He was hungry!\n");
        } else if (strcmp(cave_location, "cavern") == 0) {
            char cavern_location[50];
            printf("From cavern: nearside, farside?\n");
            scanf("%s", cavern_location);

            if (strcmp(cavern_location, "nearside") == 0) {
                char nearside_location[50];
                printf("From nearside: lookup, lookdown?\n");
                scanf("%s", nearside_location);

                if (strcmp(nearside_location, "lookup") == 0) {
                    printf("THE HUNT IS OVER!\nYou fell in a bottomless pit!\n");
                } else if (strcmp(nearside_location, "lookdown") == 0) {
                    printf("THE HUNT IS OVER!\nA giant bat carried you off!\n");
                } else {
                    printf("Invalid location!\n");
                }
            } else if (strcmp(cavern_location, "farside") == 0) {
                printf("THE HUNT IS WON! You found the Wumpus. Quick Shoot.\n");
            } else {
                printf("Invalid location!\n");
            }
        } else {
            printf("Invalid location!\n");
        }
    } else if (strcmp(location, "cliffs") == 0) {
        char cliffs_location[50];
        printf("From cliffs: ledges, peaks?\n");
        scanf("%s", cliffs_location);

        if (strcmp(cliffs_location, "ledges") == 0) {
            char ledges_location[50];
            printf("From ledges: high, low?\n");
            scanf("%s", ledges_location);

            if (strcmp(ledges_location, "high") == 0) {
                char high_location[50];
                printf("From high ledges: eagle, rattlesnake?\n");
                scanf("%s", high_location);

                if (strcmp(high_location, "eagle") == 0) {
                    printf("THE HUNT IS OVER!\nAn eagle plucked your eyes out!\n");
                } else if (strcmp(high_location, "rattlesnake") == 0) {
                    printf("THE HUNT IS OVER!\nWhy? Of course, it bit you!\n");
                } else {
                    printf("Invalid location!\n");
                }
            } else if (strcmp(ledges_location, "low") == 0) {
                printf("THE HUNT IS OVER!\nYour hunt was uneventful.\n");
            } else {
                printf("Invalid location!\n");
            }
        } else if (strcmp(cliffs_location, "peaks") == 0) {
            char peaks_location[50];
            printf("From peaks: snow, tree-line?\n");
            scanf("%s", peaks_location);

            if (strcmp(peaks_location, "snow") == 0) {
                printf("THE HUNT IS OVER!\nAn avalanche buries your party.\n");
            } else if (strcmp(peaks_location, "tree-line") == 0) {
                char tree_line_location[50];
                printf("From tree-line: crag, cave?\n");
                scanf("%s", tree_line_location);

                if (strcmp(tree_line_location, "crag") == 0) {
                    printf("THE HUNT IS OVER!\nThough, you smelled wumpus in the area!\n");
                } else if (strcmp(tree_line_location, "cave") == 0) {
                    printf("THE HUNT IS WON!\nYou found the wumpus!\n");
                } else {
                    printf("Invalid location!\n");
                }
            } else {
                printf("Invalid location!\n");
            }
        } else {
            printf("Invalid location!\n");
        }
    } else {
        printf("Invalid location!\n");
    }

    return 0;
}