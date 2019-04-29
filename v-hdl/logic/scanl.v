`timescale 1ns / 1ps
module scanl(f, a, b, c);
    output f;
    input a, b, c;
    reg f;
    always @(a or b or c)
        if(a==1) begin
            f = b;
//            f = b & c;
        end 
        else begin
            f = c;
        end
endmodule
