# How the Pre-commit Hook Script Works For Style Checking

For the core parts of RTEMS, the coding style is defined 
[here](https://docs.rtems.org/branches/master/eng/coding-conventions.html). It 
can get quite tricky most especially for newcommers to get it right when sending 
patches. As a result, the RTEMS Project has put in place a functionality to help 
new commers and existing developers automatically check for style differences in 
their patches. 

This functionality is enabled by using an already written git pre-commit hook 
script found in rtems.git/hooks/pre-commit. Follow these steps to make use of it:

* Firstly, make sure you have  Python 3 installed.
* Install clang-format
```
sudo apt install clang-format
```
* Go to rtems.git/.git/hooks/pre-commit.sample and rename pre-commit.sample to 
  pre-commit.
* Copy and paste the contents of rtems.git/hooks/pre-commit to the renamed file 
  (rtems.git/.git/hooks/pre-commit).
  
At this point, everything is set and you can start contributing to the codebase. 
This will operate in the **default mode** in which upon commiting, the script 
checks for style differences and if it finds any, it prints out the number of 
style issues as well as the affected files. Also, the commit aborts.

There is another mode known as the **nonstrict mode** which does everything in the 
default mode except for the fact that the commit does not abort. This mode is enabled 
by simply making a change to your local git configuration file before commiting:
```
git config style.mode "nonstrict"
```

Furthermore, there is another mode which prints out the style issues but in more detail 
clearly showing what the patch looked like before and and how it is supposed to look like. 
It is enabled just like the ``nonstrict`` mode:
```
git config style.verbose "verbose"
```

In order to bypass the entire pre-commit hook script, add the ``--no-verify`` option 
upon commiting.
