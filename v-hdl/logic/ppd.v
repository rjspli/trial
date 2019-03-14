`timescale 1ns / 1ps
module ppd(sel, a, b, c, d);
    input a, b, c;
    input [1:0] sel;
    output d;
    reg d;
    always @ (sel or a or b or c)
        case (sel)
            2'b11:d = a;
            2'b10:d = b;
            default:d = c;
        endcase
endmodule
