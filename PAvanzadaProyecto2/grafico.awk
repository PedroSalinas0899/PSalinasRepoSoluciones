BEGIN{
    print "digraph G {"
    print "rankdir = LR ;"
}


{
    col1[NR] = $1
    col2[NR] = $2
    col3[NR] = $3
    col4[NR] = $4
    col5[NR] = $5
    col6[NR] = $6
    colY[NR] = $11
}


END{
    for ( i = 1; i <= NR; i++ ){
        if ( col1[i] == "ATOM"){
            print "node [ shape = circle ]"
            printf "%s%s%s%s%s [ label = \" %s \"]\n", col3[i], col4[i], col5[i], col6[i], col2[i], col3[i]
            print "node [ shape = box ]"
            printf "%s%s%s%s%s -> %s%s%s\n", col3[i], col4[i], col5[i], col6[i], col2[i], col4[i], col5[i], col6[i]
        }
    }
    
    for ( i = 1; i <= NR; i++ ){
        if ( col1[i] == "ATOM" ){
            if ( col4[i] != col4[i+1] || col6[i] != col6[i+1] ){
                if ( col5[i] == col5[i+1] && col1[i+1] != "HETATM" ){
                    printf "%s%s%s -> %s%s%s [ label = \" Cadena %s \"];\n", col4[i], col5[i], col6[i], col4[i+1], col5[i+1], col6[i+1], col5[i]
                }
            }
        }
    }
    
    for ( i = 1; i <= NR; i++ ){
        if ( col1[i] == "ATOM" ){
            if ( col4[i] != col4[i+1] || col6[i] != col6[i+1] ){
                if ( col5[i] == col5[i+1] ){
                    print "node [ shape = diamond ]"
                    printf "%s%s%s [ label = \" %s \"]\n", col4[i], col5[i], col6[i], col4[i]
                    printf "%s%s%s -> %s\n",col4[i], col5[i], col6[i], colY[i]
                }
                else if ( col4[i] != col4[i+1] && col5[i] != col5[i+1] && col6[i] != col6[i+1] ){
                    print "node [ shape = diamond ]"
                    printf "%s%s%s [ label = \" %s \"]\n", col4[i], col5[i], col6[i], col4[i]
                    printf "%s%s%s -> %s\n",col4[i], col5[i], col6[i], colY[i]
                }
            }
        }
    }
    print "}"
}
