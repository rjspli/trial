`timescale 1ns / 1ps
module AutoPlay(
    input CLK,
    input BTN,
    input BTN_s,
    output PWM
    );
    wire f_1sec;
    reg [26:0] cnt_1sec=0;
    reg [26:0] cnt_1sec_cmp=0;
    reg [3:0] state_tone=0;
    always @ (posedge CLK) begin
        case(state_tone)
        0:if(BTN) begin state_tone <= 1;
                if(BTN_s)
                    cnt_1sec_cmp<=125-1;
                else
                    cnt_1sec_cmp<=125000000-1;
            end
        1:if(f_1sec) state_tone <= 2;
        2:if(f_1sec) state_tone <= 3;
        3:if(f_1sec) state_tone <= 4;
        4:if(f_1sec) state_tone <= 5;
        5:if(f_1sec) state_tone <= 6;
        6:if(f_1sec) state_tone <= 7;
        7:if(f_1sec) state_tone <= 8;
        8:if(f_1sec) state_tone <= 0;
        default: state_tone <= 0;
        endcase
    end

    always @(posedge CLK) begin
         cnt_1sec <= cnt_1sec +1;     
         if(cnt_1sec ==cnt_1sec_cmp)
             cnt_1sec <=0;
         else if(state_tone==0)
             cnt_1sec <=0;
    end
    assign f_1sec=(cnt_1sec==cnt_1sec_cmp);
    
    reg [7:0] w_BTN;
    MelodyScale MelodyScale_0(CLK, w_BTN, PWM);
    always @(state_tone) begin
        case(state_tone)
            0:w_BTN <= 0;
            1:w_BTN <= 1;
            2:w_BTN <= 2;
            3:w_BTN <= 4;
            4:w_BTN <= 8;
            5:w_BTN <= 16;
            6:w_BTN <= 32;
            7:w_BTN <= 64;
            8:w_BTN <= 128;
            default:w_BTN <= 0;
        endcase
    end
endmodule