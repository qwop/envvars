// MemDC.h: interface for the MemDC class.
// �ڴ�DC,���������λͼ��ʾ
// ���಻�ú����麯��,�̳д�����ζ�ű������ģ��ʵ�ֶ�̬��
//////////////////////////////////////////////////////////////////////

#if !defined(__MEMDC_H__)
#define __MEMDC_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class MemDC
{
public:
	MemDC( void );
	MemDC( HDC hDC );
	MemDC( HDC hDC, int nWidth, int nHeight, COLORREF clrBackground = 0xFFFFFF );
	MemDC( MemDC & other );
	~MemDC( void );

	MemDC & operator = ( MemDC const & other );
	operator HDC( void ) const { return _hMemDC; }
	operator HBITMAP( void ) const { return _hBitmap; }
	operator BOOL( void ) const { return _hMemDC != NULL && _hBitmap != NULL; }
	int Width( void ) const { return _nWidth; }
	int Height( void ) const { return _nHeight; }
	//void SetSizes( SIZE si ) { _nWidth = si.cx; _nHeight = si.cy; }
	BOOL IsTransparent( void ) const { return _bIsTransparent; }
	COLORREF TransparentColor( void ) const { return _clrTransparent; }

	BOOL Create( HDC hDC );
	BOOL Create( HDC hDC, int nWidth, int nHeight );
	BOOL Create( HDC hDC, int nWidth, int nHeight, COLORREF clrBackground );
	BOOL Create( HDC hDC, int nWidth, int nHeight, COLORREF clrBackground, COLORREF clrTransparent );
	BOOL Copy( MemDC const & other );
	void Destroy( void );
	void EnableTransparent( BOOL bIsTransparent, COLORREF clrTransparent = 0 );
	void SetBackground( COLORREF clrBackground, BOOL bFill = FALSE );
	/* ����һ��λͼ,���ֻ���������λͼ,����Ϻ�Ӧ�õ���DetachBitmap()������� */
	HBITMAP AttachBitmap( HBITMAP hBitmap );
	/* λͼ������� */
	HBITMAP DetachBitmap( void );
	/* ���ݹ���Ȩ,�Լ�����������Դ */
	BOOL PassTo( MemDC & other );
	/* ��ת */
	BOOL RotateGdiplus( double angle, MemDC * pMemDC );
#ifdef _DEBUG
	BOOL RotateCxImage( double angle, MemDC * pMemDC );
#endif
	BOOL StretchBlt( HDC hDestDC, int xDest, int yDest, int nDestWidth, int nDestHeight, int x, int y, int width, int height, int nMode = HALFTONE ) const;
	BOOL StretchToDC( HDC hDestDC, int xDest, int yDest, int nDestWidth, int nDestHeight, int nMode = HALFTONE ) const;
	BOOL BitBlt( HDC hDestDC, int xDest, int yDest, int nDestWidth, int nDestHeight, int x, int y ) const;
	BOOL CopyToDC( HDC hDestDC, int xDest, int yDest ) const;
	BOOL TransparentBlt( HDC hDestDC, int xDest, int yDest, int nDestWidth, int nDestHeight, int x, int y, int width, int height, int nMode = HALFTONE ) const;
	BOOL TransparentToDC( HDC hDestDC, int xDest, int yDest, int nDestWidth, int nDestHeight, int nMode = HALFTONE ) const;

private:
	int _nWidth, _nHeight;
	HDC _hMemDC;
	HBITMAP _hBitmap;
	COLORREF _clrBackground; // ����ɫ
	COLORREF _clrTransparent; // ͸��ɫ
	BOOL _bIsTransparent; // �Ƿ�͸��
};

#endif // !defined(__MEMDC_H__)
