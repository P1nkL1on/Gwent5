## Fetch info from `Gwent.one`

Put into the Linux terminal, swap 112112 to wished card pid:

`wget https://gwent.one/en/beta/card/112112 -q -O - | grep -Po "((?<=\"gscard__category\">).*(?=<)|(?<=\"gscard__title\">).*(?=<)|(?<=\"gscard__ability\">).*\\.(?=<)|(?<=\"obgcard__strength\">).*(?=<)|(?<=\"obgcard obgcard--medium ).*(?=\")|(?<=src=\\\")https.*/card/.*(.mp3)(?=\\\"))" | sed -e 's/<[^>]*>//g'`

### Example output:

```
Avallac'h: Sage
Mage Elf 
Spawn a default copy of a random Gold or Silver unit from your opponent's starting deck.
https://gwent.one/audio/card/ob/en/AVLC_Q311_01022646.mp3
https://gwent.one/audio/card/ob/en/AVLC_Q311_00454814.mp3
https://gwent.one/audio/card/ob/en/AVLC_Q311_00584753.mp3
https://gwent.one/audio/card/ob/en/AVLC_AVALLACH_01040188.mp3
https://gwent.one/audio/card/ob/en/AVLC_Q311_00312745.mp3
Neutral Gold
3
```

which are name, tags, ability and sounds

The image is available at the address:

```
https://gwent.one/image/card/low/cid/png/112112.png
```
