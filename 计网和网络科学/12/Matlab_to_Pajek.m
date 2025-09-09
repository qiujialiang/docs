function Matlab_to_Pajek(A,k)
    if nargin==1
       str='Pajek_data1.net'
    else
       str=['Pajek_data',int2str(k),'.net']
    end
    n=length(A);
    v=1:n;
    fid=fopen(str,'w'); %创建文本文件
    fprintf(fid,'%s%d\n','*Vertices ',n); %写入字符串换行
    for i=1:n
        fprintf(fid,'%d ',v(i)); %写入节点编号
        fprintf(fid,'"%d"\n',v(i)); %写入双引号换行
    end
    fprintf(fid,'%s\n%s\n','*Arcs','*Edges'); %写入两个字符串
    A=tril(A); %下三角元素
    [u,v]=find(A);
    n=length(u); %非零元素个数
    for i=1:n
        fprintf(fid,' %d %d 1\n',u(i),v(i)); %写入边信息
    end
    fclose(fid);
end