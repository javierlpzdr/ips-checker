//
//  terminal.c
//  Producto2
//
//  Created by Javier López (UOC) on 12/12/2019.
//  Copyright © 2019 Javier López (UOC). All rights reserved.
//

#include "terminal.h"

void ask(char question[], char output[]) {
    printf("%s", question);
    scanf("%s", output);
}
