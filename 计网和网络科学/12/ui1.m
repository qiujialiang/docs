function varargout = ui1(varargin)
% UI1 MATLAB code for ui1.fig
%      UI1, by itself, creates a new UI1 or raises the existing
%      singleton*.
%
%      H = UI1 returns the handle to a new UI1 or the handle to
%      the existing singleton*.
%
%      UI1('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in UI1.M with the given input arguments.
%
%      UI1('Property','Value',...) creates a new UI1 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before ui1_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to ui1_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help ui1

% Last Modified by GUIDE v2.5 08-Dec-2024 13:10:58

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @ui1_OpeningFcn, ...
                   'gui_OutputFcn',  @ui1_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before ui1 is made visible.
function ui1_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to ui1 (see VARARGIN)
    axes(handles.axes1); %清空绘图区
    cla reset;
    axes(handles.axes2);
    cla reset;
    axes(handles.axes3);
    cla reset;    
    handles.m0=10; %设置默认参数
    handles.m=2;
    handles.N=15;
    handles.mode=1;
    handles.p=0.1;
    handles.random_p=0.15;
    handles.zero_p=0;
    handles.num=9;
    handles.s=20;
    handles.numNode=10;
    handles.Num=20;
    handles.K=4;
    handles.P=0.2;
    handles.Mode=1;
    
% Choose default command line output for ui1
handles.output = hObject;

% Update handles structure
guidata(hObject, handles); %保存参数

% UIWAIT makes ui1 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = ui1_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on selection change in popupmenu1.
function popupmenu1_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    str=get(hObject,'String'); % 获取当前对象
    val=get(hObject,'Value'); % 获取当前对象的值
    switch str{val} % 根据用户选择的下拉菜单项的索引，使用switch语句来决定执行哪个case分支
        case '孤立节点'
            handles.mode=1;
        case '构成完全图'
            handles.mode=2;
        case '随机连接'
            handles.mode=3;
    end
    guidata(hObject,handles) %保存
% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu1 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu1


% --- Executes during object creation, after setting all properties.
function popupmenu1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit1_Callback(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    str=get(hObject,'String'); % 获取当前对象
    val=get(hObject,'Value'); % 获取当前对象的值
    handles.p=str2double(str);
% Hints: get(hObject,'String') returns contents of edit1 as text
%        str2double(get(hObject,'String')) returns contents of edit1 as a double


% --- Executes during object creation, after setting all properties.
function edit1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)

% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    axes(handles.axes1); %清空绘图区
    cla reset; 
    m0=handles.m0; %获取参数
    m=handles.m;
    N=handles.N;
    se=handles.mode;
    if m>m0
        disp("参数不合法");return;
    end
    x=100*rand(1,m0); %构造初始画图m0个节点
    y=100*rand(1,m0);
    if se==1
        A=zeros(m0);
    elseif se==2
        A=ones(m0);
        A(1:m0+1:m0^2)=0; %对角线元素置0
    else
        A=zeros(m0);
        B=rand(m0);
        B=tril(B); %截取下三角元素
        A(B<=0.1)=1; %概率0.1进行连边
        A=A+A'; %构造邻接矩阵
    end
    for k=m0+1:N
        x(k)=100*rand; %生成画图坐标
        y(k)=100*rand;
        p=(sum(A)+1)/sum(sum(A)+1); %计算节点连接概率
        pp=cumsum(p); %求累计分布
        A(k,k)=0; %邻接矩阵扩充维数
        ind=[]; %初始集合
        while length(ind)<m
            jj=find(pp>rand); %赌轮法选择连边节点编号
            jj=jj(1);
            ind=union(ind,jj); %使用unicn保证节点不重复
        end
        A(k,ind)=1;
        A(ind,k)=1;%新的邻接矩阵
    end
    plot(handles.axes1,x,y,'ro','MarkerEdgeColor','g','MarkerFaceColor','r','MarkerSize',8);
    hold on;
    handles.martix=A;
    A=tril(A);
    [i,j]=find(A); %找邻接矩阵下三角元素的非零元素
    for k=1:length(i)
        plot(handles.axes1,[x(i(k)),x(j(k))],[y(i(k)),y(j(k))],'LineWidth',1.2)
    end
    guidata(hObject, handles);
function edit2_Callback(hObject, eventdata, handles)
% hObject    handle to edit2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit2 as text
%        str2double(get(hObject,'String')) returns contents of edit2 as a double
    str=get(hObject,'String'); % 获取当前对象
    val=get(hObject,'Value'); % 获取当前对象的值
    handles.m0=str2double(str);
    guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function edit2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit3_Callback(hObject, eventdata, handles)
% hObject    handle to edit3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    
% Hints: get(hObject,'String') returns contents of edit3 as text
%        str2double(get(hObject,'String')) returns contents of edit3 as a double
    str=get(hObject,'String'); % 获取当前对象
    val=get(hObject,'Value'); % 获取当前对象的值
    handles.m=str2double(str);
    guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function edit3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit4_Callback(hObject, eventdata, handles)
% hObject    handle to edit4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit4 as text
%        str2double(get(hObject,'String')) returns contents of edit4 as a double
    str=get(hObject,'String'); % 获取当前对象
    val=get(hObject,'Value'); % 获取当前对象的值
    handles.N=str2double(str);
    guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function edit4_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    axes(handles.axes1);
    cla reset;


% --- Executes on button press in pushbutton4.
function pushbutton4_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    axes(handles.axes2); %清空绘图区
    cla reset;    
    random_p=handles.random_p; %获取参数
    zero_p=handles.zero_p;
    B=handles.martix;
    r=sum(B,2); %计算出度
    n=length(B);
    if zero_p==0
        zero_p=1/n;
    end
    A=zeros(n);
    for i=1:n
        for j=1:n
            if r(i)>0
                A(i,j)=random_p/n+(1-random_p)*B(i,j)/r(i);%构造状态转移矩阵
            else
                A(i,j)=zero_p;
            end
        end
    end
    [x,y]=eigs(A',1);%特征向量归一化
    x=x/sum(x);%和为1
    bar(handles.axes2,x);%绘制柱状图

% --- Executes on button press in pushbutton5.
function pushbutton5_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    axes(handles.axes2);
    cla reset;



function edit5_Callback(hObject, eventdata, handles)
% hObject    handle to edit5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit5 as text
%        str2double(get(hObject,'String')) returns contents of edit5 as a double
    str=get(hObject,'String'); % 获取当前对象
    val=get(hObject,'Value'); % 获取当前对象的值
    handles.zero_p=str2double(str);
    guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function edit5_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit6_Callback(hObject, eventdata, handles)
% hObject    handle to edit6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit6 as text
%        str2double(get(hObject,'String')) returns contents of edit6 as a double
    str=get(hObject,'String'); % 获取当前对象
    val=get(hObject,'Value'); % 获取当前对象的值
    handles.random_p=str2double(str);
    guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function edit6_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit8_Callback(hObject, eventdata, handles)
% hObject    handle to edit8 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit8 as text
%        str2double(get(hObject,'String')) returns contents of edit8 as a double
    str=get(hObject,'String'); % 获取当前对象
    val=get(hObject,'Value'); % 获取当前对象的值
    handles.num=str2double(str);
    guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function edit8_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit8 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit9_Callback(hObject, eventdata, handles)
% hObject    handle to edit9 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit9 as text
%        str2double(get(hObject,'String')) returns contents of edit9 as a double
    str=get(hObject,'String'); % 获取当前对象
    val=get(hObject,'Value'); % 获取当前对象的值
    handles.p=str2double(str);
    guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function edit9_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit9 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton6.
function pushbutton6_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    axes(handles.axes1);
    cla reset;    
    n=handles.num; %节点数量
    t=0:2*pi/n:2*pi; %生成角度向量
    m=nchoosek(n,2); %生成边的数量
    x=cos(t); %计算节点坐标
    y=sin(t);
    %axis([-1.1,1.1,-1.1,1.1]) %设置坐标轴范围
    %plot(handles.axes1,x,y,'o','Color','k') %绘制初始节点
    hold on;
    z=rand(1,m); %生成随机数
    p=handles.p;
    ind1=(z<=p); %决定哪些边保留
    ind2=squareform(ind1); %将逻辑向量转换为邻接矩阵
    handles.martix=ind2;
    [i,j]=find(ind2);
    plot(handles.axes1,x,y,'o','Color','k') %绘制节点
    for k=1:length(i) %绘制每条边
       line(handles.axes1,[x(i(k)),x(j(k))],[y(i(k)),y(j(k))],'Color','k')
    end
    guidata(hObject, handles);

% --- Executes on button press in pushbutton7.
function pushbutton7_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    axes(handles.axes1);
    cla reset;


% --- Executes on button press in pushbutton8.
function pushbutton8_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton8 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    A=handles.martix;
    d=sum(A); %度
    ave_degree=mean(d); %平均度
    
    d=sum(A); %计算度
    M=sum(d)/2; %总边数
    [i,j]=find(triu(A));
    ki=d(i);kj=d(j);
    r=(ki*kj'/M-(sum(ki+kj)/2/M)^2)/(sum(ki.^2+kj.^2)/2/M-(sum(ki+kj)/2/M)^2);
    if isequal(A',A)
        A=graph(A);
    else
        A=digraph(A);
    end
    dist=distances(A);
    D=max(max(dist));
    Ldist=tril(dist);
    he=sum(nonzeros(Ldist));
    n=numnodes(A);
    L=he/nchoosek(n,2);
    text15_handle=findobj('Tag','text15');
    set(text15_handle,'String',['同配系数为:',num2str(r),'    ','图直径为:', num2str(D) ...
                                ,'    ','平均路径长度为:',num2str(L),'    ','总边数为:',num2str(M) ...
                                ,'    ','平均度为:',num2str(ave_degree)])

% --- Executes on button press in pushbutton9.
function pushbutton9_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton9 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    text15_handle=findobj('Tag','text15');
    set(text15_handle,'String','');

% --- If Enable == 'on', executes on mouse press in 5 pixel border.
% --- Otherwise, executes on mouse press in 5 pixel border or over text15.
function text15_ButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to text15 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    str=get(hObject,'String'); % 获取当前对象
    val=get(hObject,'Value'); % 获取当前对象的值
    handles.N=str2double(str);
    guidata(hObject, handles);


function edit10_Callback(hObject, eventdata, handles)
% hObject    handle to edit10 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit10 as text
%        str2double(get(hObject,'String')) returns contents of edit10 as a double
    str=get(hObject,'String'); % 获取当前对象
    val=get(hObject,'Value'); % 获取当前对象的值
    handles.numNode=str2double(str);
    guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function edit10_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit10 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton10.
function pushbutton10_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton10 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    axes(handles.axes1);
    cla reset;
    numNode=handles.numNode;
    numEdge=handles.s;
    srcNodes = randi(numNode, 1, numEdge); % 源节点
    tarNodes = randi(numNode, 1, numEdge); % 目标节点
    
    G = digraph(srcNodes, tarNodes);
    handles.martix = adjacency(G);
    plot(handles.axes1,G);
    guidata(hObject,handles) %保存

% --- Executes on button press in pushbutton11.
function pushbutton11_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton11 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    axes(handles.axes1);
    cla reset;



function edit11_Callback(hObject, eventdata, handles)
% hObject    handle to edit11 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit11 as text
%        str2double(get(hObject,'String')) returns contents of edit11 as a double
    str=get(hObject,'String'); % 获取当前对象
    val=get(hObject,'Value'); % 获取当前对象的值
    handles.s=str2double(str);
    guidata(hObject, handles);
    
% --- Executes during object creation, after setting all properties.
function edit11_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit11 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton12.
function pushbutton12_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton12 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    A=handles.martix;
    N=length(A);
    deg=sum(A); %计算各节点的度
    degrange=minmax(deg); %求度的取值范围
    pinshu=hist(deg,[degrange(1):degrange(2)]); %求度取值的频数
    df=pinshu/N; %度的频率分布
    bar(handles.axes3,[degrange(1):degrange(2)],df,'r'); %画度分布柱状图

% --- Executes on button press in pushbutton13.
function pushbutton13_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton13 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    axes(handles.axes3);
    cla reset;


% --- Executes on button press in pushbutton14.
function pushbutton14_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton14 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    axes(handles.axes1);
    cla reset;    
    N=handles.Num;
    K=handles.K;
    p=handles.P;
    t=0:2*pi/N:2*pi-2*pi/N;  %生成最近邻耦合网络个节点坐标的参数方程的角度
    x=100*sin(t);
    y=100*cos(t);
    A=zeros(N); %邻接矩阵初始化
    plot(handles.axes1,x,y,'ro','MarkerEdgeColor','g','MarkerFaceColor','r','MarkerSize',6);
    hold on;
    if handles.Mode==1
        for i=1:N %循环构造最临近K耦合网络的邻接矩阵
            for j=i+1:i+K/2
                jj=(j<=N)*j+(j>N)*mod(j,N); %如果j超过N要除以N的余数
                A(i,jj)=1;
                A(jj,i)=1;
            end
        end
        for i=1:N %随机重连
            for j=i+1:i+K/2
                jj=(j<=N)*j+(j>N)*mod(j,N);
                ChangeV=randi([1,N]); %产生随机整数
                if rand<=p && A(i,ChangeV)==0 && i~=ChangeV
                    A(i,jj)=0; %删除原边
                    A(jj,i)=0;
                    A(i,ChangeV)=1; %重连新边
                    A(ChangeV,i)=1;
                end
            end
        end
        for i=1:N-1
            for j=i+1:N
                if A(i,j)~=0
                    plot(handles.axes1,[x(i),x(j)],[y(i),y(j)],'LineWidth',1.2);
                end
            end
        end
        handles.martix=A;
    else
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
                source=randi(N); %随机源节点
                target=randi(N); %随机目标节点
                while target==source %自环
                    target=randi(N); 
                end
                while A(source, target) == 1 %存在边
                    source = randi(N);
                    target = randi(N);
                end
                if rand<p
                   A(source,target)=1; %加边
                   A(target,source)=1;
                end
            end
        end
        for i=1:N-1
            for j=i+1:N
                if A(i,j)~=0
                    plot(handles.axes1,[x(i),x(j)],[y(i),y(j)],'LineWidth',1.2);
                end
            end
        end
        handles.martix=A;
    end
    guidata(hObject, handles);
    

% --- Executes on button press in pushbutton15.
function pushbutton15_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton15 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    axes(handles.axes1);
    cla reset;


function edit12_Callback(hObject, eventdata, handles)
% hObject    handle to edit12 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit12 as text
%        str2double(get(hObject,'String')) returns contents of edit12 as a double
    str=get(hObject,'String'); % 获取当前对象
    val=get(hObject,'Value'); % 获取当前对象的值
    handles.Num=str2double(str);
    guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function edit12_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit12 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit13_Callback(hObject, eventdata, handles)
% hObject    handle to edit13 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit13 as text
%        str2double(get(hObject,'String')) returns contents of edit13 as a double
    str=get(hObject,'String'); % 获取当前对象
    val=get(hObject,'Value'); % 获取当前对象的值
    handles.K=str2double(str);
    guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function edit13_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit13 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit14_Callback(hObject, eventdata, handles)
% hObject    handle to edit14 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit14 as text
%        str2double(get(hObject,'String')) returns contents of edit14 as a double
    str=get(hObject,'String'); % 获取当前对象
    val=get(hObject,'Value'); % 获取当前对象的值
    handles.P=str2double(str);
    guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function edit14_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit14 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in popupmenu2.
function popupmenu2_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu2 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu2
    str=get(hObject,'String'); % 获取当前对象
    val=get(hObject,'Value'); % 获取当前对象的值
    switch str{val} % 根据用户选择的下拉菜单项的索引，使用switch语句来决定执行哪个case分支
        case '随机重连'
            handles.mode=1;
        case '加边'
            handles.mode=2;
    end
    guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function popupmenu2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
