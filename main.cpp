#include <Windows.h>
//�E�B���h�E�v���V�[�W��
LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	//���b�Z�[�W�ɉ����ČŗL�̏������s��
	switch (msg) {
		//�E�B���h�E���j�����ꂽ
	case WM_DESTROY:
		//OS�ɑ΂���,�A�v���̏I����`����
		PostQuitMessage(0);
		return 0;
	}

	//�W���̃��b�Z�[�W���s��
	return DefWindowProc(hwnd, msg, wparam, lparam);
}
//Windows�A�v���ł̃G���g���[�|�C���g
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//�R���\�[���ւ̕����o��
	OutputDebugStringA("Hello,Directx!!\n");

	//�E�B���h�E�T�C�Y
	const int window_width = 1200;//��
	const int window_height = 720;//�c

	//�E�B���h�E�N���X�̐ݒ�
	WNDCLASSEX w{};
	w.cbSize = sizeof(WNDCLASSEX);			
	w.lpfnWndProc = (WNDPROC)WindowProc;	 //�E�B���h�E�v���V�[�W���ݒ�
	w.lpszClassName = L"DirectXGame";		 //�E�B���h�E�N���X��
	w.hInstance = GetModuleHandle(nullptr);	 //�E�B���h�E�n���h��
	w.hCursor = LoadCursor(NULL, IDC_ARROW); //�J�[�\���w��

	//�E�B���h�E�N���X��OS�ɂ���
	RegisterClassEx(&w);
	//�E�B���h�E�T�C�Y{�����W,�����W,����,����}
	RECT wrc = { 0,0,window_width,window_height };
	//�����ŃT�C�Y����������
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

	//�E�B���h�E�I�u�W�F�N�g�̐���
	HWND  hwnd = CreateWindow(w.lpszClassName,
		L"DirectXGame",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		wrc.right - wrc.left,
		wrc.bottom - wrc.top,
		nullptr,
		nullptr,
		w.hInstance,
		nullptr);
	//�E�B���h�E��\����Ԃɂ���
	ShowWindow(hwnd, SW_SHOW);

	MSG msg{};	//���b�Z�[�W

	//DirectX������������������
	
	//DirectX���������������܂�

	//�Q�[�����[�v
	while (true)
	{
		if (PeekMessage
		(&msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		//�~�{�^���ŏI�����b�Z�[�W���o���烋�[�v����������
		if (msg.message == WM_QUIT) {
			break;
		}
		//DirectX���t���[�������@��������

		//DirectX���t���[�������@�����܂�
	}
	//�E�B���h�E�N���X��o�^
	UnregisterClass(w.lpszClassName, w.hInstance);
	return 0;
}