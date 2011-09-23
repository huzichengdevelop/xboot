#ifndef __SURFACE_H__
#define __SURFACE_H__

#include <xboot.h>
#include <graphic/pixel.h>
#include <graphic/rect.h>

enum surface_pixels {
	SURFACE_PIXELS_NEEDFREE	= 0x0,
	SURFACE_PIXELS_DONTFREE	= 0x1,
};

struct surface_t {
	/* surface pixel information */
	struct pixel_info info;

	/* surface's width and height */
	u32_t w, h;

	/* pitch of one scan line */
	u32_t pitch;

	/* surface pixels flag */
	enum surface_pixels flag;

	/* pointer to pixel data */
	void * pixels;

    /* clipping information */
	struct rect_t clip;

	/* private data */
	void * pirv;
};


bool_t surface_set_clip_rect(struct surface_t * surface, struct rect_t * rect);
bool_t surface_get_clip_rect(struct surface_t * surface, struct rect_t * rect);

struct surface_t * surface_alloc_from(void * pixels, u32_t w, u32_t h, enum pixel_format fmt);
void surface_free(struct surface_t * surface);

bool_t surface_draw_point(struct surface_t * surface, s32_t x, s32_t y, u32_t c);
bool_t surface_draw_points(struct surface_t * surface, const struct point_t * points, u32_t count, u32_t c);

bool_t surface_fill_rect(struct surface_t * surface, const struct rect_t * rect, u32_t c);
bool_t surface_fill_rects(struct surface_t * surface, const struct rect_t * rects, u32_t count, u32_t c);

#endif /* __SURFACE_H__ */
