function varargout = Brainscope(varargin)
% BRAINSCOPE MATLAB code for Brainscope.fig
%      BRAINSCOPE, by itself, creates a new BRAINSCOPE or raises the existing
%      singleton*.
%
%      H = BRAINSCOPE returns the handle to a new BRAINSCOPE or the handle to
%      the existing singleton*.
%
%      BRAINSCOPE('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in BRAINSCOPE.M with the given input arguments.
%
%      BRAINSCOPE('Property','Value',...) creates a new BRAINSCOPE or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Brainscope_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Brainscope_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help Brainscope



% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Brainscope_OpeningFcn, ...
                   'gui_OutputFcn',  @Brainscope_OutputFcn, ...
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


% --- Executes just before Brainscope is made visible.
function Brainscope_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Brainscope (see VARARGIN)



% Dataset 2 : used for Reset button
ClearY=[0];  
handles.ClearY = ClearY;



%handles.currentData = handles.Y;
%plot(handles.currentData);


% Choose default command line output for Brainscope
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes Brainscope wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = Brainscope_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Dataset 1 : used for Start button
A=[];
% Creating Serial Objects
EEG=serial('COM5','BaudRate',9600,'DataBits',8);
fopen(EEG);

% Reading Data From COM5
for i=1:50
    data=fread(EEG,1);
    A=[A data];
end
fclose(EEG);

Y=A;
handles.Y = Y;

plot(handles.Y,'b');



% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
plot(handles.ClearY);


% --------------------------------------------------------------------
function Untitled_1_Callback(hObject, eventdata, handles)
% hObject    handle to Untitled_1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
