/* All below functions return 1 when they succeed */

/* Prints the alphabet */
int lsh_abc(char **args);

/* Prints the corresponding letter for the number inputted
 * i.e. 1 is A, 2 is B, etc.
 * Returns an error if no number is included
 * Returns an error if the number is not between 1 and 26
 */
int lsh_letter(char **args);

/* Prints example exhaustive visualizations
 * There are currently 2
 * Prints one by default if no argument is typed in, prints others with numerical args
 */
int lsh_eviz(char **args);

/* Prints example leaf visualizations
 * There are currently 2
 * Prints one by default if no argument is typed in, prints others with numerical args
 */
int lsh_lviz(char **args);

/* Prints example word visualizations
 * There are currently 2
 * Prints one by default if no argument is typed in, prints others with numerical args
 */
int lsh_wviz(char **args);

/* Prints example subtree visualizations
 * There are currently 2
 * Prints one by default if no argument is typed in, prints others with numerical args
 */
int lsh_sviz(char **args);
