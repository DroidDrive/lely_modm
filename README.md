# lely_modm

This is a modm repository (+module) containing a [fork](https://github.com/DroidDrive/lely-core) of the [lely canopen stack](https://opensource.lely.com/canopen/).



## What was changed?

a lot

* multiple C Enum fixes which lead to duplicate names with modm
* the use of a lot of standard libraries was minimized
* the use of malloc was minimized
* the c++ api was adapted to contain (and work with) with changes made by the [ecss lely fork](https://gitlab.com/n7space/canopen/lely-core)
* multiple implementation details where `ifdef` -guarded because the only work with filesystems and linux devices 

## How to use?

* include the repository in your modm project.xml

  ```xml
  <repository>
      <path>../libs/lely_modm/repo.lb</path>
  </repository>
  ```

* include the module in your modm project.xml

```xml
<module>lely_modm:lely-core</module>
```

* inside your porject, do 
  * `lbuild build`
  * `scons`

## What is in there?

* the module contains:
  * the lely-core stack ([fork](https://github.com/DroidDrive/lely-core))
  * lely addons directory, containing some utility functions

## Misc

+ for lely to work (or behave in desired ways), multiple `define` flags can be altered inside the `module.lb` file 

