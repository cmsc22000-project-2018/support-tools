#Support Tools

##Description
This program allows for the visualization of tries (see https://en.wikipedia.org/wiki/Trie). This tool was developed at the University of Chicago, during Spring Quarter of 2018, for CMSC 22000 - Intro to Software Development, in conjunction with a Redis (https://redis.io/) module for use with tries. This program uses a shell to facillitate interaction between the user and the trie they're visualizing.

#Using the shell
These instructions will guide you through using the Support Tools trie visualization suite.

## Prerequisites
Make sure you have the most recent master branch of the code from out Github repo(https://github.com/cmsc22000-project-2018/support-tools) !
You will also need a command line tool, like Terminal, to build and interact with the code.

## Making the code
Simply open the support-tools directory in a command line tool, switch into the consolidated_shell directory, and type:
$ make all

## Opening the shell
From here, simply print ./shell

## Running commands
The shell greets the user. Type "help" at any point to see a full list of commands!

### Selecting your trie
Right now, all commands within the shell must indicate the index of one of three hardcoded tries, so 0, 1, or 2. In the future, we will allow for a key-based interaction with a remote Redis server. This document will be updated when such functionality is integrated.

### Visualizing your trie
The basic format of print commands in the shell is:
$ print <trie index>
Running this command alone will print every node in the trie.

By addending "all [prefix]" to the above command, only the nodes flowing down from the entered prefix will be printed.

By addending "only-words" to the basic print command, only the nodes of the trie marked as words will be printed.
Additionally, a command in the form of:
$ print <trie index> only-words [prefix]
Will print only the nodes flowing down from the entered prefix that are also words.

By addending "only-leaves" to the basic print command, only the leaves of the given trie will be printed.
Additionally, a command in the form of:
$ print <trie index> only-leaves [prefix]
Will print only the leaves flowing down from the entered prefix.

The command:
$ print <trie-index> n-completions [prefix] n
Will print the first n words of a given trie flowing down from the entered prefix.

### Getting Help
Typing:
$ help
at any time will print a list of all possible commands and their explanations.

Additionally:
$ help all-nodes
$ help only-leaves
$ help only-words
$ help n-completions
Will specifically explain the referenced command.

### Exiting the shell
Simply type
$ quit

# Examples
These examples specifically use a trie, referenced by index 0, that contains the leaves "bets" and "betters"

## Basic print

$ print 0

Would yield:

b

b-e

b-e-t

b-e-t-s

b-e-t-t

b-e-t-t-e

b-e-t-t-e-r

b-e-t-t-e-r-s

## All nodes with prefix

$ print 0 all bette

Would yield:

b-e-t-t-e

b-e-t-t-e-r

b-e-t-t-e-r-s

## Printing only words

$ print 0 only-words

Would yield:

b-e

b-e-t

b-e-t-s

b-e-t-t-e-r

b-e-t-t-e-r-s

## Printing only words with a prefix

$ print 0 only-words bette

Would yield:

b-e-t-t-e-r

b-e-t-t-e-r-s

## Printing only leaves

$ print 0 only-leaves

Would yield:

b-e-t-s

b-e-t-t-e-r-s

## Printing only leaves with a prefix

$ print 0 only-leaves bette

Would yield:

b-e-t-t-e-r-s

## Printing n-completions

$ print 0 n-completions b 1

Would yield:

b-e

#Authors

This project was made by:

Hongji Li
Maxine King
Elizabeth Crowdus
Richard Pei
Marco Kaisth

# Acknowledgments

This project was supervised by:

Borja Sotomayor
Lydia Filipe

Additionally, this document is based on a template created by Github user PurpleBooth, availible here: https://gist.github.com/PurpleBooth/109311bb0361f32d87a2