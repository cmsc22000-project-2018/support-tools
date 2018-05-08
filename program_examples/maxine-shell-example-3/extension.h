/* All below functions return 1 when they succeed */

/* Prints the alphabet */
int abc();

/* Prints the corresponding letter for the number inputted
 * i.e. 1 is A, 2 is B, etc.
 * Returns an error if no number is included
 * Returns an error if the number is not between 1 and 26
 */
int letter(char **args);

/* Prints example exhaustive visualizations
 * There are currently 2
 * Prints one by default if no argument is typed in, prints others with numerical args
 */
int eviz(char **args);

/* Prints example leaf visualizations
 * There are currently 2
 * Prints one by default if no argument is typed in, prints others with numerical args
 */
int lviz(char **args);

/* Prints example word visualizations
 * There are currently 2
 * Prints one by default if no argument is typed in, prints others with numerical args
 */
int wviz(char **args);

/* Prints example subtree visualizations
 * There are currently 2
 * Prints one by default if no argument is typed in, prints others with numerical args
 */
int sviz(char **args);
