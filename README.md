ftr
===============

ftr is a cross-platform (Android/iOS) front-end development framework. The core code is written in C++. The bottom layer is based on OpenGL drawing. The upper layer implements a streamlined typesetting engine and a JS/JSX running environment. The goal is to develop GUI applications on this basis, which can take both development speed and operation efficiency into account.

* Only `iOS` and `Android` systems are supported for the time being, this does not include `AndroidTV`, because `TV` applications are very different from mobile applications

* From here, [`Go API Index`](http://ngui.fun/doc/) can go to `API Documents Index`

| ![Screenshot](http://ngui.fun/img/0x0ss.jpg) | ![Screenshot](http://ngui.fun/img/0x0ss_3.jpg) | ![Screenshot](http://ngui.fun/img/0x0ss_4.jpg) |
|--|--|--|


Build and install ftrp
===============

1. Build must dependent `Xcode` / `JDK1.7` / `Android-SDK-23` / `NDK` / `python` / `nodejs` / `yasm`.

2. Setting environment variable `JAVA_HOME` and `ANDROID_HOME`

Compile and install ftrp `make install`, It takes a long time.

use ftrp tools create project.

first create an empty file directory, then execute in the directory

`ftrp init`

export ios xcode project `ftrp export ios`


# Simple Examples

This is a simple program to display Hello world on the screen

```jsx
import { GUIApplication, Root } from 'ftr'
new GUIApplication().start(
	<Root>hello world!</Root>
)
```

You can get a more detailed [`Examples`]

# Start Usage

If you've never used ftr before, you can start from here and build your ftr program step by step.

## Install ftrp

First, you need to install the toolkit provided by `ftrp`

* Install `ftrp` using nodejs `npm` 

* Open `Terminal` and execute the following command：

```sh
# shell
$ sudo npm install -g ftrp

```
	
* Running `ftrp` requires dependency on `nodejs` and `python2.7`

* And now do not support the `windows` system, you need to use it under `mac`

## Create new project

Create a new `ftrp` project using the following `shell` command：

```sh
# shell
$ mkdir myproject
$ cd myproject
$ ftrp init
```

## Build project

This step compresses and packages the JavaScript code and resource files inside the project,
If this is a new project, you can skip this step and go directly to the next step

```js
# shell
$ ftrp build
```

## Export project

This step exports [`Xcode`] or [`Android Studio`] project，because you eventually publish the program that be a `.apk` or `.ipa`

```js
# shell
# export xcode ios project
$ ftrp export ios
# export android studio project
$ ftrp export android
```

After exporting the project, next you can open it using [`Xcode`] and [`Android Studio`]

## ftrp test http server

`ftrp` provides a test http server, each time you change the `js` or `jsx` code, you don't have to reinstall every time.

Execute the following code to start it：

```js
# shell
$ ftrp
```

# Downloads

* Examples demo [`Android APK`] Install package

* Project [`Source code`] from `Github`


[`Examples`]: https://github.com/louis-tru/ftr/tree/master/demo
[`Xcode`]: https://developer.apple.com/library/content/documentation/IDEs/Conceptual/AppDistributionGuide/ConfiguringYourApp/ConfiguringYourApp.html
[`Android Studio`]: https://developer.android.com/studio/projects/create-project.html
[`Android APK`]: https://github.com/louis-tru/ftr/releases/download/v0.1.0/examples-release.apk
[`NPM`]: https://www.npmjs.com/package/ftrp
[`Source code`]: https://github.com/louis-tru/ftr
