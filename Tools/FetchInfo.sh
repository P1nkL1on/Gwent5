#! /bin/sh

ID=$1
HTML=$(wget https://gwent.one/en/beta/card/$ID -q -O tmp.txt)
NAME=$(grep -Po "(?<=\"gscard__title\">).*(?=<)" tmp.txt)
TAGS=$(grep -Po "(?<=\"gscard__category\">).*(?=<)" tmp.txt)
TEXT=$(grep -Po "(?<=\"gscard__ability\">).*(?=<)" tmp.txt | sed -e 's/<[^>]*>//g')
POWER=$(grep -Po "(?<=\"obgcard__strength\">).*(?=<)" tmp.txt)
RARITY_FACTION=$(grep -Po "(?<=\"obgcard obgcard--medium ).*(?=\")" tmp.txt)
SOUNDS=$(grep -Po "(?<=src=)\\\"https.*/card/.*(.mp3)\\\"" tmp.txt | tr '\n' ',')
# wget https://gwent.one/en/beta/card/$ID -q -O - | grep -Po "|||)" | sed -e 's/<[^>]*>//g'
echo 'id = "'$ID'";'
echo 'name = "'$NAME'";'
echo 'text = "'$TEXT'";'
echo 'url = "https://gwent.one/image/card/low/cid/png/" + id + ".png";'
echo 'tags = { '$TAGS'};'
echo 'power = powerBase = '$POWER';'
echo 'faction = rarity = '$RARITY_FACTION';'
echo 'sounds = {'
echo '    '$SOUNDS
echo '};'
