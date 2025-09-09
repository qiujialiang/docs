N=20;K=4;p=0.2;
t=0:2*pi/N:2*pi-2*pi/N;
x=100*sin(t);
y=100*cos(t);
plot(x,y,'ro','MarkerEdgeColor','g','MarkerFaceColor','r','MarkerSize',6);
hold on;
A=zeros(N);
for i=1:N
    for j=i+1:i+K/2
        jj=(j<=N)*j+(j>N)*mod(j,N);
        A(i,jj)=1;
        A(jj,i)=1;
    end
end
for i=1:N
    for j=i+1:i+K/2
        jj=(j<=N)*j+(j>N)*mod(j,N);
        ChangeV=randi([1,N]);
        if rand<=p && A(i,ChangeV)==0 && i~=ChangeV
            A(i,jj)=0;
            A(jj,i)=0;
            A(i,ChangeV)=1;
            A(ChangeV,i)=1;
        end
    end
end
for u=1:N-1
    for j=i+1:N
        if A(i,j)~=0
            plot([x(i),x(j)],[y(i),y(j)],'LineWidth',1.2)
        end
    end
end
Matlab_to_Pajek(A)

function Matlab_to_Pajek(A,k)
    if nargin==1
       str='Pajek_data1.net'
    else
       str=['Pajek_data',int2str(k),'.net']
    end
    n=length(A);
    v=1:n;
    fid=fopen(str,'w');
    fprintf(fid,'%s%d\n','*Vertices ',n);
    for i=1:n
        fprintf(fid,'%d ',v(i));
        fprintf(fid,'"%d"\n',v(i));
    end
    fprintf(fid,'%s\n%s\n','*Arcs','*Edges');
    A=tril(A);
    [u,v]=find(A);
    n=length(u);
    for i=1:n
        fprintf(fid,' %d %d 1\n',u(i),v(i));
    end
    fclose(fid);
end

N=20;K=4;p=0.2;
t=0:2*pi/N:2*pi-2*pi/N;
x=100*sin(t);
y=100*cos(t);
plot(x,y,'ro','MarkerEdgeColor','g','MarkerFaceColor','r','MarkerSize',6);
hold on;
A=zeros(N);
for i=1:N
    for j=i+1:i+K/2
        jj=(j<=N)*j+(j>N)*mod(j,N);
        A(i,jj)=1;
        A(jj,i)=1;
    end
end
for i=1:N
    for j=i+1:i+K/2
        source=randi(N);
        target=randi(N);
        while target==source
            target=randi(N);
        end
        while A(source, target) == 1
            source = randi(N);
            target = randi(N);
        end
        if rand<p
           A(source,target)=1;
           A(target,source)=1;
        end
    end
end
for u=1:N-1
    for j=i+1:N
        if A(i,j)~=0
            plot([x(i),x(j)],[y(i),y(j)],'LineWidth',1.2)
        end
    end
end
Matlab_to_Pajek(A,2)
