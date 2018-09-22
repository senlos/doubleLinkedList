Create a new repository on your github account. Pay attention on the correct local path. Files in the directory will shown.

Changes in folders will be automatically sync between atom and github desktop.

// So, next go on seeing.

Notice that color represents meaning. Color green represents new added. Yellow means modify, and red is delete.

Every change should be commit before going on. After commiting, the color will change from green to gray, whether the file name or code lines.

Obviously, save before commit, and push after commit.

Each commit can change one or more files.

Notice that the changes haven't shown on web site. Maybe we haven't push.

By now, I have commit all of three new file added. As a result, their name turns from green into gray.

After I enter this sentence and save the file, the file name directly change into yellow, means modify. This happens both in Atom and github desktop.

Modify is define as some hierarchy. If a file is changed, its name turns yellow. And look in detail, how the changes of content represent.

Changes are based on lines. New line shows in green, and removed line shows in red. If a line is changed, old content shows in red, and new content shows in green. In other word, yellow color is not used inside file.

It's easy to create a second branch. But here comes a core problem you haven't understand: how different branches be exist at the same time locally.

If its a new branch, you can publish it. After that I can check it on the website.

I can directly change the content, then commit and finish all operation. Because I owned the master branch and change on it directly.

After I modify locally, should I then push it? I realize that may cause some conflict or overwrite.

A comparison should be held between to different branches.

Since it didn't mention about fetch but push right away, let's try it.

Luckily, it comes out an error. It cues "The repository has been updated since you last pulled. Try pulling before pushing." Also notice that there is a force push option. Maybe consider later.

I try pull, but it cause another error and refuse me. Because it seems like some problem in version control. Here is the online version and local version conflict. With the same branch, say master. If after a local push, then another changes commit happen on web. After that I change locally and try to make push. Here comes to the error. No matter pull or push cause error warning.

It's ok to change or edit files content on website end. What you have changed need a commit as well.

Undo commit is ok, where brings you back.

I think its still some problem. After fetch, what I have done on web didn't appear locally in Atom. But luckily changes can be seen in github desktop. github desktop can show the difference, but can't edit. where atom can edit, but did't indicate the changes. Maybe can just edit it in Atom. Changes saved will appear in github desktoop verion, while Atom shows a unstable copy.
