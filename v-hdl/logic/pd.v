`timescale 1ns / 1ps
module pd(sel, a, b, c, d);
    input a, b, c;
    input [1:0] sel;
    output d;
    reg d;
    always @ (sel or a or b or c)
        if(sel == 2'b11)
            d = a;
        else if(sel == 2'b10)
            d = b;
        else
            d = c;
endmodule
