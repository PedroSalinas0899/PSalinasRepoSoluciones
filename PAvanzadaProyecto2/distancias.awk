BEGIN{
}


{
    col1[NR] = $1
    col2[NR] = $2
    col3[NR] = $3
    col4[NR] = $4
    col5[NR] = $5
    col6[NR] = $6
    colx[NR] = $7
    coly[NR] = $8
    colz[NR] = $9
    colX[NR] = $10
    colY[NR] = $11
    colZ[NR] = $12
}


END{
    rango = 0
    for ( i = 1; i <= NR; i++ ){
        if ( col1[i] != "ATOM" && col1[i] != "HETATM" ){
            rango = 0 + col1[i]
        }
    }
    
    x = 1
    for ( i = 1; i <= NR; i++ ){
        if ( col1[i] == "HETATM" ){
            col2[i] = 0 + x
            x = x + 1
        }
    }
    
    distancia = 0
    for ( i = 1; i <= NR; i++ ){
        if ( col1[i] == "HETATM" && col2[i] == posicion ){
            for ( j = 1; j <= NR; j++ ){
                if ( col1[j] == "ATOM" && colY[j] != col4[i] && colZ[j] != col2[i] ){
                    distancia = ((colx[j]-colX[i])^2 + (coly[j]-colY[i])^2 + (colz[j]-colZ[i])^2 )^0.5
                    if ( distancia <= rango){
                        for (k = 1; k <= NR; k++){
                            if ( col4[k] == col4[j] && col5[k] == col5[j] && col6[k] == col6[j] ){
                                colY[k] = col4[i]
                                colZ[k] = col2[i]
                                printf "%s %s %s %s %s %s %s %s %s %s %s %s\n", col1[k], col2[k], col3[k], col4[k], col5[k], col6[k], colx[k], coly[k], colz[k], colX[k], colY[k], colZ[k]
                            }
                        }
                    }
                }
            }
        }
    }
    
    for ( i = 1; i <= NR; i++ ){
        if ( col1[i] == "HETATM" && col2[i] == posicion ){
            printf "%s %s %s %s %s %s %s %s %s %s %s %s\n", col1[i], col2[i], col3[i], col4[i], col5[i], col6[i], colx[i], coly[i], colz[i], colX[i], colY[i], colZ[i]
        }
    }
}
