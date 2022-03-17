#!/bin/bash
for FILE in $(cat ./modified_files.txt)
do
	cp ~/xv6-public/${FILE} ./180070032/
done

tar -zcvf 180070032.tar.gz 180070032
