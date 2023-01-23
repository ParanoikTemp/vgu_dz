program Troyka;
var n: integer;
begin
    write('Write number: ');
    readln(n);
    while n > 1 do
    begin
        if (n mod 3 = 0) then n := n div 3 else 
        begin
            write('False');
            break;
        end;
    end;
    if n = 1 then write('True');
end.
