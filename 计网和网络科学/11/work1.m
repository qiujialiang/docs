function varargout = work1(varargin)
% WORK1 MATLAB code for work1.fig
%      WORK1, by itself, creates a new WORK1 or raises the existing
%      singleton*.
%
%      H = WORK1 returns the handle to a new WORK1 or the handle to
%      the existing singleton*.
%
%      WORK1('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in WORK1.M with the given input arguments.
%
%      WORK1('Property','Value',...) creates a new WORK1 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before work1_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to work1_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help work1

% Last Modified by GUIDE v2.5 01-Dec-2024 14:25:07

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @work1_OpeningFcn, ...
                   'gui_OutputFcn',  @work1_OutputFcn, ...
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


% --- Executes just before work1 is made visible.
function work1_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to work1 (see VARARGIN)
    handles.peaks=peaks(35); % 设置handles结构体中的peaks字段为peaks函数生成的35个点。
    handles.membrane=membrane;
    [x,y]=meshgrid(-8:.5:8); % 使用meshgrid函数生成一个网格，x和y的范围从-8到8，步长为0.5
    r=sqrt(x.^2+y.^2)+eps; % 计算网格上每一点的欧几里得距离r，并加上一个很小的数eps以避免除以零
    sinc=sin(r)./r; % 计算sinc函数，即sin(r)/r
    cosi=cos(r)./r; % 计算cosi函数，即cos(r)/r
    handles.sinc=sinc;
    handles.cosc=cosi;
    handles.current_data=handles.peaks; % 将handles结构体中的peaks字段的值赋给current_data字段
    contour(handles.current_data) % 使用contour函数绘制当前数据的等高线图
% Choose default command line output for work1
    handles.output = hObject;

% Update handles structure
    guidata(hObject, handles);

% UIWAIT makes work1 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = work1_OutputFcn(hObject, eventdata, handles) 
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

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu1 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu1
    str=get(hObject,'String'); % 获取当前对象
    val=get(hObject,'Value'); % 获取当前对象的值
    switch str{val}; % 根据用户选择的下拉菜单项的索引，使用switch语句来决定执行哪个case分支
        case 'Peaks'
            handles.current_data=handles.peaks;
        case 'Membrane'
            handles.current_data=handles.membrane;
        case 'Sinc'
            handles.current_data=handles.sinc;
        case 'Cosi'
            handles.current_data=handles.cosi;
    end
    guidata(hObject,handles)
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


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    surf(handles.current_data);
% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    mesh(handles.current_data)

% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    contour(handles.current_data)


% --- Executes on button press in pushbutton5.
function pushbutton5_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
    waterfall(handles.current_data)
