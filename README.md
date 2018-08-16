# s7a73farmsPartyBadge

![s7a73farmsPartyBadge](https://raw.githubusercontent.com/s7a73farm/s7a73farm_Party_Badge_DC26/blob/master/images/badge_x3.jpg)

# Getting Started to program it
```
Modify the tx/Makefile & rx/Makefile 
Line 16: AVRDUDE = avrdude -c usbasp -p t84 -U flash:w:$(PROJECT).hex
Change usbasp to usbtiny or whatever programmer  you are using.
```

## Build Master Badge
```
git clone git@github.com:SocialGeeks/s7a73farmsPartyBadge.git
cd firmware/tx
make clean
make
make upload
```

## Build Slave Badge
```
git clone git@github.com:SocialGeeks/s7a73farmsPartyBadge.git
cd firmware/rx
make clean
make
make upload
```

