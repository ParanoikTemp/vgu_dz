program Troyka;
var N, K: integer;
begin
    write('Write number: ');
    readln(N);
    K := 0;
    while K * K <= N do
    begin
        K := K + 1;
    end;
    Write('Result: ');
    Write(K - 1);
end.
