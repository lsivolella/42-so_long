/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mapping.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:24:29 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/05/22 10:58:09 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_MAPPING_H
# define KEY_MAPPING_H

typedef enum	e_keyboard_key
{
	key_a		= 97,
	key_d		= 100,
	key_e		= 101,
	key_q		= 113,
	key_s		= 115,
	key_w		= 119,
	key_esc		= 65307,
	key_left	= 65361,
	key_up		= 65362,
	key_right	= 65363,
	key_down	= 65364
}	t_keyboard_key;

typedef enum	e_event
{
	on_keydown		= 2,
	on_keyup		= 3,
	on_mousedown	= 4,
	on_mouseup		= 5,
	on_mousemove	= 6,
	on_expose		= 12,
	on_destroy		= 17
}	t_event;

typedef enum	e_mask
{
	mask_no_event				= 0L,		// NoEventMask
	mask_key_press				= 1L<<0,	// KeyPressMask
	mask_key_release			= 1L<<1,	// KeyReleaseMask
	mask_button_press			= 1L<<2,	// ButtonPressMask
	mask_button_release			= 1L<<3,	// ButtonReleaseMask
	mask_enter_window			= 1L<<4,	// EnterWindowMask
	mask_leave_window			= 1L<<5,	// LeaveWindowMask
	mask_pointer_motion			= 1L<<6,	// PointerMotionMask
	mask_pointer_motion_hint	= 1L<<7,	// PointerMotionHintMask
	mask_button_1_motion		= 1L<<8,	// Button1MotionMask
	mask_button_2_motion		= 1L<<9,	// Button2MotionMask
	mask_button_3_motion		= 1L<<10,	// Button3MotionMask
	mask_button_4_motion		= 1L<<11,	// Button4MotionMask	
	mask_button_5_motion		= 1L<<12,	// Button5MotionMask
	mask_button_motion			= 1L<<13,	// ButtonMotionMask
	mask_keymap_state			= 1L<<14,	// KeymapStateMask
	mask_exposure_mask			= 1L<<15,	// ExposureMask
	mask_visibility_change		= 1L<<16,	// VisibilityChangeMask
	mask_structure_notify		= 1L<<17,	// StructureNotifyMask
	mask_resize_redirect		= 1L<<18,	// ResizeRedirectMask
	mask_substructure_notif		= 1L<<19,	// SubstructureNotifyMask
	mask_substructure_redirect	= 1L<<20,	// SubstructureRedirectMask
	mask_focus_change			= 1L<<21,	// FocusChangeMask
	mask_property_change		= 1L<<22,	// PropertyChangeMask
	mask_colormap_change		= 1L<<23,	// ColormapChangeMask
	mask_owner_grab_button		= 1L<<24	// OwnerGrabButtonMask
}	t_mask;

// sorce: https://harm-smits.github.io/42docs/libs/minilibx/events.html
#endif