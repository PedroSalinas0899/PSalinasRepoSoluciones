BEGIN{
print "digraph G {"
print "rankdir = LR ;"
print "node [ shape = box ]"
col2[NR]
col3[NR]
col4[NR]
col5[NR]
}

{
for (i = 1;i <= NR; i++){
	col3[NR] = $3
	col4[NR] = $4
	col5[NR] = $5
	col6[NR] = $6
}

}

END{
for (i = 1; i <= NR; i++){
	printf "%s%s%s%s[ label = \" %s \"]\n", col3[i], col4[i], col5[i], col6[i], col3[i]
	printf "%s%s%s%s -> %s%s%s\n", col3[i], col4[i], col5[i], col6[i], col4[i], col5[i], col6[i]
}
print "node [ shape = box ]\n"
for (i = 1; i <= NR; i++){
	if ( col4[i] != col4[i+1] || col6[i] != col6[i+1]){
		if ( col5[i] == col5[i+1]){
			printf "%s%s%s -> %s%s%s [ label = \" Cadena %s \"];\n", col4[i], col5[i], col6[i], col4[i+1], col5[i+1], col6[i+1], col5[i]
		}
	}
}
for (i = 1; i <= NR; i++){
	printf "%s%s%s[ label = \" %s \"]\n", col4[i], col5[i], col6[i] ,col4[i]
}
print "}"
}
