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
    aux = 1
    sumax = 0
    sumay = 0
    sumaz = 0
    i = 1
    
    while (i <= NR){
        if ( col6[i] == col6[i+1] ){
            aux = aux + 1
            sumax = sumax + colx[i]
            sumay = sumay + coly[i]
            sumaz = sumaz + colz[i]
            i = i + 1
        }
        else if ( col6[i] != col6[i+1] && aux > 1 ){
            sumax = sumax + colx[i]
            sumay = sumay + coly[i]
            sumaz = sumaz + colz[i]
            colX[i] = sumax / aux
            colY[i] = sumay / aux
            colZ[i] = sumaz / aux
            aux = 1
            sumax = 0
            sumay = 0
            sumaz = 0
            i = i + 1
        }
        else{
            aux = 1
            colX[i] = colx[i]
            colY[i] = coly[i]
            colZ[i] = colz[i]
            i = i + 1
        }
    }
    
    for (i = 1; i <= NR; i++){
        if ( col6[i] != col6[i+1] ){
            printf "%s %s %s %s %s %s %s %s %s %s %s %s\n", col1[i], col2[i], col3[i], col4[i], col5[i], col6[i], colx[i], coly[i], colz[i], colX[i], colY[i], colZ[i]
        }
    }
}
